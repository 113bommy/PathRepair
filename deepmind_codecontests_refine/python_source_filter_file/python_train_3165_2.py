class Ranges:
    def __init__(self):
        self.ranges = []

    def add_range(self, start, end):
        self.ranges.append((start, end))

    def is_path(self, start, end):
        start -= 1
        end -= 1

        lower = min(start, end)
        higher = max(start, end)

        queue = [(start, self.ranges[start])]
        seen = set()

        while len(queue) > 0:
            idx, r = queue.pop()

            if idx == end:
                return True

            seen.add(idx)
            reachable = [i for i in range(0, len(self.ranges)) if self._path_exists(idx, i) and i not in seen]
            reachable = list(map(lambda x: (x, self.ranges[x]), reachable))
            queue.extend(reachable)

        return False

    def _path_exists(self, x, y):
        x -= 1
        y -= 1

        a, b = self.ranges[x]
        c, d = self.ranges[y]

        return c < a < d or c < b < d


def main():
    nqueries = int(input())
    ranges = Ranges()

    for x in range(nqueries):
        qtype, start, end = map(int, input().split())

        if qtype == 1:
            # print("   handling 1")
            ranges.add_range(start, end)
        else:
            # print("   handling 2")
            print("YES" if ranges.is_path(start, end) else "NO")


if __name__ == "__main__":
    main()
