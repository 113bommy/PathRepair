a, b = map(int, input().split())
c = input()
 
print(c[:b-1] + c[b-1].lower() + c[b:]