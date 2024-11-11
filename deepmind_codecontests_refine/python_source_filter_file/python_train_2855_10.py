from collections import deque
import bisect
n=int(input())
list1=list(map(int,input().split()))
list1.sort()
list1=deque(list1)
while(True):

    x=list1.pop()
    y=list1.pop()
    if(x>y):
        x-=y
        bisect.insort(list1,x)
        bisect.insort(list1,y)
    else:
        bisect.insort(list1,x)
        bisect.insort(list1,y)
        break
# print(list1)
print(sum(list1))
        