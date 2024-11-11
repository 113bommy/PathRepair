n = int(input())
lang_cnt = {}
for lang in input().split():
    if lang not in lang_cnt:
        lang_cnt[lang] = 0
    lang_cnt[lang] += 1
m = int(input())
best_vp_cnt = -1
best_as_cnt = -1
best_movie = 0
audio = input().split()
subtitles = input().split()
for i in range(1, m + 1):
    vp_cnt = lang_cnt.get(audio[i - 1], 0)
    as_cnt = lang_cnt.get(subtitles[i - 1], 0)
    if vp_cnt > best_vp_cnt:
        best_vp_cnt = vp_cnt
        best_as_cnt = as_cnt
        best_movie = i
    elif vp_cnt == best_vp_cnt and as_cnt > best_as_cnt:
        best_vp_cnt = vp_cnt
        best_as_cnt = as_cnt
        best_movie = i
print(best_movie)
