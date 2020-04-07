import sys

input = sys.stdin.readline
print = sys.stdout.write

input_string = input()
n, k = tuple(map(int, input_string.split()))

input_string = input()
scores = list(map(int, input_string.split()))

pass_score = scores[k - 1]

print(str(len(list(filter(lambda x: x >= pass_score and x > 0, scores)))))