import heapq


class Segment:
    def __init__(self, li, ri) -> None:
        self.size = ri - li + 1
        self.li = li
        self.ri = ri

    def __str__(self) -> str:
        return '(' + str(self.size) + ', ' + str(self.li) + ')'


def comparator(s, o):
    if o.size > s.size:
        return False
    if o.size < s.size:
        return True
    return s.li < o.li


setattr(Segment, "__lt__", comparator)

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())

        arr = [0 for _ in range(n)]

        segs = [Segment(1, n)]

        for i in range(1, n + 1):
            seg = heapq.heappop(segs)
            l = seg.size

            if l % 2:
                mp = ((seg.li + seg.ri) // 2)
            else:
                mp = ((seg.li + seg.ri - 1) // 2)

            arr[mp - 1] = i

            if seg.size > 1:
                if seg.li < mp:
                    heapq.heappush(segs, Segment(seg.li, mp - 1))
                if seg.ri > mp:
                    heapq.heappush(segs, Segment(mp + 1, seg.ri))

        print(arr)