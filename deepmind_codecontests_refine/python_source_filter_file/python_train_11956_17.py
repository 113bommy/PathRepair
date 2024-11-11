_,k=int(input()),int(input())
print(sum([min([i,k-i])for i in list(map(int,input().split()))]))
