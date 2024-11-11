from sys import stdin ,stdout
from os import path
if(path.exists('input.txt')):
    stdin = open("input.txt","r")
x=stdin.readline()
k=0
for i in range(len(x)):
	t=x.find('bear',i)
	if t>=0:
		k+=len(x)-t-3
		
stdout.write(str(k)+'\n')