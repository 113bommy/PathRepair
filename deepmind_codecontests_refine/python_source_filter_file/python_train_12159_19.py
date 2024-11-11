N = int(input())
S, T = input().split()
print("".join(map(lambda s,t:f"{s}{t}", S, T)))