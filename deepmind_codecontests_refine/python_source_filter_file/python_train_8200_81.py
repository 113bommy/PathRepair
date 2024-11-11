n=int(input())
a=list(map(int,input().split()))
print ('Yes' if len(a)==len(set(a)) else 'No')