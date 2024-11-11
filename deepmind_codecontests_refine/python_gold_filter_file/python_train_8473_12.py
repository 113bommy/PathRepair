n = int(input())
arr = list(map(int, input().split()))
track = [0] * 7
for i in arr:
    track[i - 1] += 1

if(track[6] != 0 or track[4] != 0):
    print(-1)
else:
    c1 = track[0] == (track[3] + track[5])
    if(c1):
        _124 = track[3]
        track[1] -= _124
        if(track[1] >= 0):
            #use remaining 2s on 126
            _126 = track[1]
            #subtract 126 pairings from 6
            track[5] -= _126
            if(track[5] == track[2]):
                #works
                _136 = track[2]
                for i in range(_124):
                    print(1,2,4)
                for i in range(_126):
                    print(1,2,6)
                for i in range(_136):
                    print(1,3,6)
            else:
                print(-1)
        else:
            print(-1)
    else:
        print(-1)