// SysInfo.cpp : CSysInfo ��ʵ��

#include "stdafx.h"
#include "SysInfo.h"
#include <atlcomtime.h>

// CSysInfo
STDMETHODIMP CSysInfo::RecText(BSTR bstrContent)
{
	// TODO: Add your implementation code here
	ATLASSERT(NULL != m_spiSocketConnect);
	if(NULL == bstrContent || NULL == m_spiSocketConnect)
		return E_POINTER;
	m_spiSocketConnect->put_ActiveTime(COleDateTime::GetCurrentTime().m_dt);
	/// �봦���յ����ı���Ϣ��������ʾֱ�ӻظ�ԭ����
	ULONG nReqID = 0;
	m_spiSocketConnect->AsynSendText(bstrContent,&nReqID);
	return S_OK;
}

STDMETHODIMP CSysInfo::RecJson(ULONG nReqID,BSTR bstrReqName,BSTR bstrContent)
{
	// TODO: Add your implementation code here
	ATLASSERT(NULL != m_spiSocketConnect);
	if(NULL == bstrContent || NULL == m_spiSocketConnect)
		return E_POINTER;
	/// �봦���յ�����ͨJSON���ݰ�
	return S_OK;
}
