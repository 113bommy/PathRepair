a, b = map(int, input().split())
print(["NO", "YES"][abs(a-b)<2 and a+b>0])