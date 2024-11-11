S = list(input())
N = [str(int(N[0]) - 1)] + ["9"] * (len(S)-1)
print("{:.0f}".format(max(sum(map(int, N)), sum(map(int,S)))))