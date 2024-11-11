def is_peak(mountain, k):
    if mountain[k] > mountain[k-1] and mountain[k] > mountain[k+1]:
        return True
    else:
        return False

t = int(input())
for case in range(t):
    n, k = map(int, input().split())
    mountain = [int(x) for x in input().split()]


    if k == n:
        answer = 1
        for i in range(1, n-1):
            if is_peak(mountain, i):
                answer += 1

        print ("{} 1".format(answer))


    else:
        cur_max = 0
        for i in range(1, k-1):
            if is_peak(mountain, i):
               cur_max += 1
        cur_peaks = cur_max
        cur_max_index = 1

        scores = [cur_peaks]

        for i in range(1, n-k+1):
            if is_peak(mountain, i):
               cur_peaks -= 1
            if is_peak(mountain, i + k -2):
               cur_peaks += 1
            scores.append(cur_peaks)
            if cur_peaks > cur_max:
               cur_max = cur_peaks
               cur_max_index = i + 1
        print ("{} {}".format(cur_max + 1, cur_max_index))
        
