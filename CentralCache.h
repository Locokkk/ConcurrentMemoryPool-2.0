#pragma once

#include"Common.h"
#include"PageCache.h"

class CentralCache 
{
public:
	//�����Ļ����ȡһ�������Ķ����thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);//num�Ƕ�����,size���ֽ���

	//��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpans(void* start, size_t size);

	//��spanlist����page cache��ȡһ��span
	Span* GetOneSpan(size_t size);

	static CentralCache& GetInstance()
	{
		static CentralCache inst;
		return inst;
	}
private:
	CentralCache()
	{}
	CentralCache(const CentralCache&) = delete;
	SpanList _spanLists[NFREELIST];
};

//static CentralCache centralcacheInst;//��̬��������̹߳���
//����ɵ���ģʽ��Ͳ�����