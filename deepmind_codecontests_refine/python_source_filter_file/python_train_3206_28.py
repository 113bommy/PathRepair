a, b, k = map(int, input().split())

print(str(max(0, a-k))+' '+str(max(0, a+b-k)))