K, A, B = map(int, input().split())
print(max(K+1, A+(B-A)*((K-A+1)//2)+(K+1)%2))