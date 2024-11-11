from collections import *
from sys import stdin, stdout
input=stdin.readline
n,a,l,p=int(input()),list(map(int, input().split())),defaultdict(int),1
for i in range(n):p=max(p,i+1-(max(l[a[i]+1],l[a[i]-2])if l[a[i]-1]>l[a[i]+1]else max(l[a[i]+2],l[a[i]-1])));l[a[i]]=i+1;
print(p)