
import os
import subprocess
import multiprocessing

os.chdir(os.path.dirname(__file__))
os.path.dirname(os.path.realpath(__file__)) 

import os
import multiprocessing

NUMBER_OF_SESSIONS = 10

def worker():
    while True:
        os.system("dir")


if __name__ == '__main__':
    jobs = []
    for i in range( NUMBER_OF_SESSIONS ):
        p = multiprocessing.Process(target=worker)
        jobs.append(p)
        p.start()


#publihser = "C:\\Users\\Gal2IB\\Source\\Repos\\schlesg\\EltaDDSBenchmarkTester\\objs\\x64Win64VS2017\\BenchmarkType_publisher.exe"
#print(publihser)
##os.system("start /B start" + publihser +"  @cmd /k ")

##os.system(publihser)
##os.system(publihser)

##os.system("start /wait cmd /c {command}")
##multiprocessing.process(publihser)

#a = subprocess.Process(publihser, start_new_session=True, cwd = os.getcwd())
#subprocess.Popen(publihser, start_new_session=True, cwd = os.getcwd())

#a.wait()
#subprocess.call(["\\objs\\x64Win64VS2011\\BenchmarkType_publisher.exe"], cwd="C:\\Users\\Gal2IB\\Source\\Repos\\schlesg\\EltaDDSBenchmarkTester")

#os.system("start /wait cmd /c {command}")
