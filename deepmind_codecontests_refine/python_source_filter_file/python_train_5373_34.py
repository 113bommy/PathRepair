s=input()
k=int(input())
print('impossible' if k > len(s) else max(len(set(s)),k))