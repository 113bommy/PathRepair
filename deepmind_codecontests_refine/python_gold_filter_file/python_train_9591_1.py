class Solution(object):
    def getMaxAbsoluteDifference(self, arr):
        totalTestCount = 0
        totalSocialCount = 0
        for num in arr:
            if num == 1:
                totalTestCount += 1
            else:
                totalSocialCount += 1

        maxAbsDifference = 0
        for i in range(k):
            currTestCount = totalTestCount
            currSocialCount = totalSocialCount
            for j in range(i, len(arr), k):
                if arr[j] == 1:
                    currTestCount -= 1
                else:
                    currSocialCount -= 1
            maxAbsDifference = max(maxAbsDifference, abs(currTestCount - currSocialCount))

        return maxAbsDifference

def read_input(): # list
    return [int(x) for x in input().split()]

if __name__ == "__main__":
    line = read_input()
    n = line[0]
    k = line[1]
    arr = read_input()

    sol = Solution()
    result = sol.getMaxAbsoluteDifference(arr)
    print(result)