import twint
import pandas as pd
import os 
import numpy as np
import sys
print(sys.argv[1]);

c = twint.Config()
c.Username = str(sys.argv[1])
c.Limit = int(10)
c.Store_csv = True
c.Output = "tweets/tweets.csv"
twint.run.Search(c)
#df = pd.read_csv("tweets.csv")
#df.rename(columns={'tweet':'comment_text'},inplace=True)
#os.remove("tweets/tweets.csv")
#return df
