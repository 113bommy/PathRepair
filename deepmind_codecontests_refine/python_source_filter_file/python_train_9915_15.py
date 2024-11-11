
def findPeak(heights, ind_peaks, n, k):
    p1 = 0
    p2 = 0
    count = 0
    max_count = 0
    max_p1 = 0
    #print('k', k)
    for i in range(1, k):
        #print('i', i)
        if i-1 in ind_peaks:
            count += 1
            if count > max_count:
                max_count = count
                max_p1 = p1
    # print(ind_peaks)
    #print('1st count', max_count)
    p1 += 1
    p2 = k
    #print('p1,p2 iniciales', p1, p2)
    while p2 <= len(heights):
        #print('p1s', p1)

        if p1-1 in ind_peaks:
            count -= 1
        if p2-1 in ind_peaks:
            count += 1
            if count > max_count:
                #print('aaaa', max_count)
                max_count = count
                max_p1 = p1
        p2 += 1
        p1 += 1
    return max_count+1, max_p1+1


if __name__ == "__main__":
    t = int(input(''))
    res = []
    for _ in range(t):
        n, k = [int(x) for x in input('').split(' ')]
        heights = [int(x) for x in input('').split(' ')]
        ind_peaks = set()
        for i in range(n):
            if i == 0 or i == n-1:
                pass
            else:
                if heights[i-1] < heights[i] and heights[i] > heights[i+1]:
                    ind_peaks.add(i)
        #print('péeeeks', ind_peaks)

        a, b = findPeak(heights, ind_peaks, n, k)
        res.append(str(a)+' ' + str(b))
        #print('asddasd', a)
    for i in res:
        print(i)
