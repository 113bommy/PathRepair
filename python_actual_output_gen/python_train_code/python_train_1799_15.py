input()
print("three" if len(set(map(str, input().split()))) == 3 else "four")