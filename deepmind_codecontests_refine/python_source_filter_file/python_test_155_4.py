t = int(input())
for i in range(t):
    n = int(input())
    predictedRatings = list(map(int, input().split()))
    reactions = input()
    likes = dislikes = 0
    likedSongs = []
    dislikedSongs = []
    for j in range(len(reactions)):
        reaction = reactions[j]
        if reaction == '1':
            likes+=1
            likedSongs.append((predictedRatings[i], j))
        else:
            dislikes+=1
            dislikedSongs.append((predictedRatings[i], j))
    likedSongs = sorted(likedSongs, key = lambda x : x[0])
    dislikedSongs = sorted(dislikedSongs, key = lambda x : x[0])
    result = [0 for i in range(n)]
    rating = 1
    for ratings, index in dislikedSongs:
        result[index] = rating
        rating+=1
    for ratings, index in likedSongs:
        result[index] = rating
        rating+=1
    for val in result:
        print(val, end = ' ')
    print()
