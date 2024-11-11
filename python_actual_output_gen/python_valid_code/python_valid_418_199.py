a, b = map(int, input())
print([b+a,b-a][b%a>0])