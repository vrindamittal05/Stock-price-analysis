# Stock Price Analysis

This C++ program processes stock price data, calculates the maximum possible profit from a single buy-sell transaction, and analyzes daily price movements.

## Features

- Reads stock prices in `YYYY-MM-DD:price` format.
- Computes **maximum profit** achievable with one buy and one sell.
- Counts **price movement trends**: up, down, or same.

## How it Works

1. **Read Data**  
   Function: `readData`  
   - Parses input strings to extract dates and prices.  
   - Stores prices in a vector and date-price mapping in a map.

2. **Calculate Maximum Profit**  
   Function: `getMaxProfit`  
   - Finds the largest profit possible by buying low and selling high once.  
   - Single-pass algorithm with O(n) time complexity.

3. **Check Price Movements**  
   Function: `checkMovement`  
   - Counts how many times prices went up, down, or stayed the same.

## Example Input

```cpp
vector<string> stockInput = {
    "2026-01-01:100",
    "2026-01-02:105",
    "2026-01-03:102",
    "2026-01-04:110",
    "2026-01-05:108"
};
