k,s=map(int,input().split())
print(sum([min(k,s-i)-max(0,s-i-k)+1 for i in range(k+1)]))