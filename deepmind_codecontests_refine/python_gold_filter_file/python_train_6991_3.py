from sys import stdin, stdout


x,y,z = map(int,stdin.readline().split())
if(z==0 and x==y):
    stdout.write("0\n")
elif(x+z<y):
    stdout.write("-\n")
elif(y+z<x):
    stdout.write("+\n")
else:
    stdout.write("?\n")
