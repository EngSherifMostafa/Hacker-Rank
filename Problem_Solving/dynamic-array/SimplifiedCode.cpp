int calIndex(int x, int lastAnswer, int n) {
	return ((x ^ lastAnswer) % n);
}

void queryOne(const int x, const int lastAnswer, const int n, vector<vector<int>>& seqList, const int y) {
	int index = calIndex(x, lastAnswer, n);
	seqList.at(index).push_back(y);
}

int queryTwo(const int x, int& lastAnswer, const int n, const vector<vector<int>> seqList, const int y) {
	int outerIndex = calIndex(x, lastAnswer, n);

	int innerIndex = (y % seqList.at(outerIndex).size());


	lastAnswer = seqList.at(outerIndex).at(innerIndex);

	return lastAnswer;
}

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
	int lastAnswer = 0;
	int x = 0, y = 0;
	vector<int> result;
	vector<vector<int>> seqList(n);

	for (auto seq : queries)
	{
		if (seq.size() > 2)
		{
			auto queryType = seq.front();
			x = *(seq.begin() + 1);
			y = seq.back();

			if (queryType == 1)
				queryOne(x, lastAnswer, n, seqList, y);

			else if (queryType == 2)
				result.push_back(queryTwo(x, lastAnswer, n, seqList, y));
		}
	}
	return result;
}