"""
Code of Ayush Tiwari
Codeforces: servermonk
Codechef: ayush572000

"""
import sys
input = sys.stdin.buffer.readline

def solution():
    n,p,q,r=map(int,input().split())
    l=list(map(int,input().split()))
    np=-2e9
    nq=-2e9
    nr=-2e9
    for i in range(n):
        np=max(np,p*l[i])
        nq=max(nq,np+q*l[i])
        nr=max(nr,nq+r*l[i])
    print(nr)
solution()