
import os
import subprocess

os.chdir(os.path.dirname(__file__))
os.path.dirname(os.path.realpath(__file__)) 

publihser = "objs\\x64Win64VS2011\\BenchmarkType_publisher.exe"
print(publihser)
#os.system("start /B start" + publihser +"  @cmd /k ")


#os.system("start /wait cmd /c {command}")

#subprocess.Popen(publihser, shell=True, cwd = os.getcwd())

subprocess.call(["objs\\x64Win64VS2011\\BenchmarkType_publisher.exe"], cwd="D:\GITRepo\EltaDDSBenchmarkTester")

#os.system("start /wait cmd /c {command}")
