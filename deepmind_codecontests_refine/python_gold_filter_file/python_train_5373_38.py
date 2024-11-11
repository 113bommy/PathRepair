s=input()
k=int(input())
print('impossible' if k > len(s) else max(0,k-len(set(s))))