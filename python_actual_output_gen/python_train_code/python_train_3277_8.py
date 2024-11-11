import sys
inp = int(sys.stdin.readline())
out = 2
for i in range(1,inp):
  out*=i
out = out/(inp**2)
sys.stdout.write(str(int(out)))