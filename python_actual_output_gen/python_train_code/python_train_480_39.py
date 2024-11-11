n = int(input())
for i in range(n):
    s = input()
    if s[-1:-2] == "su":
        print("JAPANESE")
    elif s[-1:-2] == "po":
        print("FILIPINO")
    else:
        print("KOREAN")