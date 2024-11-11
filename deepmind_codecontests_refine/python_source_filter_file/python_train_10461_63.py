k,n,w = map(int, input().split())
result = k*(w*(w+1)/2)
print(max(0,result-n))
