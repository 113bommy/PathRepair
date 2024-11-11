from sys import setrecursionlimit
from collections import deque
import heapq
import functools
# setrecursionlimit(10**6)
def IntInput(): return int(input())
def M_IntInput(): return map(int,input().split())
def M_StrInput(): return map(int,input().split())
def IntArrayInput(): return list(map(int,input().split()))
def modInverse(p,a,m): return ((p%m)*pow(a%m,m-2,m))%m
def compare(item1, item2): return item2[0] - item1[0] if item1[0]!=item2[0] else item1[1] - item2[1]
def DFS(s,n,paths,answer):
    visited = [False] * (n+1)
    stack = []
    stack.append(s) 
    visited[s] = True
    DFSArray = []
    while stack: 
        s = stack.pop()
        DFSArray.append(s)
        flag = 0
        for i in paths[s]: 
            if visited[i] == False: 
                flag=1
                stack.append(i) 
                visited[i] = True
    
        if not flag:
            answer[s-1][1]=0
    
    while DFSArray!=[]:
        s = DFSArray.pop()
        if answer[s-1][1]<0:
            answer[s-1][1] = 0
            for i in paths[s]:
                if answer[i-1][1]>=0:
                    answer[s-1][1] += answer[i-1][1]+1

    return answer
def BFS(s,n,paths,answer): 
    visited = [False] * (n+1)
    answer[s-1][0] = 0
    queue = deque()
    queue.append(s) 
    visited[s] = True
    while queue: 
        s = deque.popleft(queue)
        for i in paths[s]: 
            if visited[i] == False: 
                queue.append(i) 
                answer[i-1][0] = answer[s-1][0] + 1
                visited[i] = True
    return answer
numbers = ["1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"]
Dict_Numbers = {"1110111":0, "0010010":1, "1011101":2, "1011011":3, "0111010":4, "1101011":5, "1101111":6, "1010010":7, "1111111":8, "1111011":9}
# ----------------------- Anshul Raj ------------------------ #

for _ in range(int(input())):
    n = int(input()) 
    array = [1]
    sumV = 1
    while(sumV!=n):
        # print(array)
        if sumV+(2*array[-1])<=n:
            sumV+=array[-1]*2
            array.append(2*array[-1])
        else:
            array.append(n-sumV)
            sumV = n
            
    array.sort()
    print(n,array)
    ans = []
    for i in range(1,len(array)):
        ans.append(str(array[i]-array[i-1]))
    
    print(len(array)-1)
    print(" ".join(ans))