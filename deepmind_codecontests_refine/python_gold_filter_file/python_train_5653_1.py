import sys
input = sys.stdin.readline
import math
import copy

for _ in range(int(input())):
    n = int(input())
    commands = []
    for i in range(n):
        commands.append(list(map(int,input().split())))
    commands.append([10**18,0])
    i = 0
    current = 0
    pos = 0
    ans = 0
    while i<n:
        start = commands[i][0]
        time = abs(pos-commands[current][1])
        finish = start+time
        if finish<=commands[i+1][0]:
            endpos = commands[current][1]
            if commands[i][1]>=min(pos,endpos) and commands[i][1]<=max(pos,endpos):
                ans+=1
            pos = endpos
            current = i+1
        else:
            time = commands[i+1][0]-start
            if commands[current][1]<pos:
                endpos = pos-time
                if commands[i][1]>=min(pos,endpos) and commands[i][1]<=max(pos,endpos):
                    ans+=1
                pos = endpos
            else:
                endpos = pos+time
                if commands[i][1]>=min(pos,endpos) and commands[i][1]<=max(pos,endpos):
                    ans+=1
                pos = endpos
        i+=1
    print(ans)