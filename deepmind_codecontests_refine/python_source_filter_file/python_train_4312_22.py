# python 3
"""
"""
from operator import itemgetter


def dima_and_continuous_line(segment_list: list) -> str:
    segment_list.sort(key=itemgetter(0))
    # print(segment_list)
    for i in range(len(segment_list)):
        for j in range(i+1, len(segment_list)):
            if segment_list[i][0] < segment_list[j][0] < segment_list[i][1] < segment_list[j][1]:
                print(segment_list[i], segment_list[j])
                return "yes"
    return "no"


if __name__ == "__main__":
    """
    Inside of this is the test. 
    Outside is the API
    """

    n = int(input())
    points = list(map(int, input().split()))
    segments = []
    for i in range(n-1):
        if points[i] < points[i+1]:
            segments.append(tuple((points[i], points[i+1])))
        else:
            segments.append(tuple((points[i+1], points[i])))
    # print(segments)
    print(dima_and_continuous_line(segments))
