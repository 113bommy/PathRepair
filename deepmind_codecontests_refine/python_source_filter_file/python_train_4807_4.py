from typing import List


class Solution:

    def NumberCircle(self, arr: List[int]):
        i = 0
        j = i + 1
        size = len(arr)
        arr.sort()
        if arr[size - 1] > sum(arr) - arr[size - 1]:
            print("NO")
        else:

            if arr[size - 1] <= arr[size - 2] + arr[0]:
                x = arr[size - 2]
                arr[size - 2] = arr[size - 1]
                arr[size - 1] = x

            if not self.check(arr, size):
                print("NO")
            else:
                print("YES")
                ss = [str(n) for n in arr]
                print(" ".join(ss).strip())

    def check(self, arr: List, size):
        for i in range(size - 2):
            if arr[i] + arr[i + 2] <= arr[i + 1]:
                return False

        if arr[size - 1] + arr[1] <= arr[0]:
            return False

        return True


sol = Solution()
size = int(input())
ns = [int(x) for x in input().split()]
sol.NumberCircle(ns)
