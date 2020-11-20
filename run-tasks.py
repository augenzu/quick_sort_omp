import os
import time

TRY_NUM = 4
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


for num_procs in [1, 2, 4, 6, 8, 10, 12, 16]:
    nsteps = 10
    start = ((num_procs + 3) // 4) * 4
    end = start * 16
    step = (end - start) // nsteps
    nums_threads = list(range(start, end + 1, step))
    if num_procs not in nums_threads:
        nums_threads = [num_procs] + nums_threads
    else:
        nums_threads += [nums_threads[-1]]
    for num_threads in nums_threads:
        task = '#BSUB -n ' + str(num_procs) + pattern + \
                'OMP_NUM_THREADS=' + str(num_threads) + \
                ' ./main ' + TIMINGS_FILE + ' ' + str(num_procs)
        with open('task.lsf', 'w') as fout:
            fout.write(task)
        os.system(cmd)
        time.sleep(1)
