def solve(n,ar):
    track = [ar[0]]

    for i in range(2,n):
        if i == n-1: continue
        if ar[i]-ar[i-1] > 0 and ar[i+1] - ar[i] > 0:
            continue
        elif ar[i]-ar[i-1] < 0 and ar[i+1] - ar[i] < 0:
            continue
        else:
            track.append(ar[i])

    track.append(ar[n-1])
    print(len(track))
    print(" ".join(map(str, track)))



if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        perm = list(map(int,input().split()))
        solve(n,perm)