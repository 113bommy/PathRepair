a, b = map(int, input().split(" "))
print([b,b+(100*(10-a))][a<10])