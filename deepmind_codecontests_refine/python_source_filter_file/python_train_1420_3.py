

n = int(input())
list = list(map(int,input().split()));

list.sort()


maxRep = 1;
curMaxRep = 0;
for i in range(n-1):
    if(list[i] == list[i+1]):
        curMaxRep += 1
        maxRep = max(maxRep,curMaxRep);
    else:
        curMaxRep =1;
print(maxRep);