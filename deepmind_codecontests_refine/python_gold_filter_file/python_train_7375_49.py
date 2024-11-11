n = int(input())
li = list(map(int,input().split()))
li.sort(reverse=True)
print(sum(li[1:2*n:2]))
