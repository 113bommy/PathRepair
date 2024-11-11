a, b, c = map(int, input().split())
print('No' if all((a*i)%b != c for i in range(1,b+1)) else 'Yes')