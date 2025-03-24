n = int(input())
dp = []

dp.append(1)
dp.append(3)

sum = 0

for i in range(2, n + 1):
    dp.append(0)
    dp[i] += dp[1] * dp[i - 1]
    sum += 2 * dp[i - 2]
    dp[i] += sum

print(dp[n])