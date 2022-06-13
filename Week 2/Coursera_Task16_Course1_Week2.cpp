set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> res;

	for (const auto& item : m)
		res.insert(item.second);
	return (res);
}
