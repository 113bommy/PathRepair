m, n = list(map(int, input().split()))
seq = list(map(int, input().split()))
keys = list(map(int, input().split()))
output =[s for s in seq if s in keys]
print(''.join(str(o) for o in output))
