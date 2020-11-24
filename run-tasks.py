import os
import time

TRY_NUM = '3_1'
TIMINGS_DIR = 'timings/'
TIMINGS_FILE = '20-11-20__' + str(TRY_NUM)

pattern = \
'''
#BSUB -W 00:01
#BSUB -o bsub-report.out
#BSUB -e bsub-report.err
#BSUB -R "span[hosts=1]"
'''

cmd = 'bsub < task.lsf'


for num_procs in [1, 2, 4, 6, 8, 10, 12, 16, 14, 18, 20]:
    nums_threads = [num_procs, num_procs * 2, num_procs * 4, num_procs * 8, num_procs * 16, num_procs * 32]
    for num_threads in nums_threads:
        task = '#BSUB -n ' + str(num_procs) + pattern + \
                'OMP_NUM_THREADS=' + str(num_threads) + \
                ' ./main ' + TIMINGS_FILE + ' ' + str(num_procs)
        with open('task.lsf', 'w') as fout:
            fout.write(task)
        os.system(cmd)
        time.sleep(1)
