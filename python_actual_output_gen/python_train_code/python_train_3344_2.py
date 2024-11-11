'''
Created on Jan 28, 2019

@author: Rares
'''
n = input()
cmd = input()
v = cmd.split(" ")
for i in range(len(v)):
    v[i] = int(v[i])

sorted(v)

rez = 0
for i in range(1,len(v),2):
    rez += (v[i]-v[i-1])

print(rez)
