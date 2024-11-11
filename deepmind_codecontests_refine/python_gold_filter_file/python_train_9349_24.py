K, A, B = map(int, input().split())
print(max(K+1, A+(B-A)*((K+1-A)//2)+(K+1-A)%2))