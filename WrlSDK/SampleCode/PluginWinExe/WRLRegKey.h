// WRLRegKey.h : ע������ͷ�ļ�����
//
//////////////////////////////////////////////////////////////////////

#pragma once

class CWrlRegKey : public CRegKey
{
public:
	CWrlRegKey(const ATL::CString& strMainRegPath,\
		const ATL::CString& strChildName, \
		HKEY hKey,REGSAM samDesired);

	virtual ~CWrlRegKey(void)
	{
		/// ����ʱ�Զ��رգ�������й¶
		Close();
	}

	/// �ж��Ƿ����ע���
	BOOL IsOpen()
	{
		return m_bOpenFlag;
	}

	/**
	 * @brief ������·����������ʵ��
	 *
	 *
	 * @param strMainRegPath ע�����λ��
	 * @param strChildName ע�����Ŀ¼����
	 * @param bCurrentUser �Ƿ�Ϊ�û�ע�������Ϊϵͳע���
	 * @return 
	 */
	BOOL NewRegPath(const ATL::CString& strMainRegPath,\
		const ATL::CString& strChildName,\
		HKEY hKey,REGSAM samDesired);

	/**
	 * @brief ���ݼ����ƻ���ַ������ͼ�ֵ
	 *
	 *
	 * @param strKeyName  ����
	 * @param strKeyValue ��ֵ
	 * @return �Ƿ�ɹ���ȡ
	 */
	BOOL GetRegStringVal(const ATL::CString& strKeyName,ATL::CString& strKeyValue);
	
	/**
	 * @brief ����ע����ַ�������ֵ
	 *
	 *
	 * @param strKeyName  ����
	 * @param strKeyValue ��ֵ
	 * @return �Ƿ�ɹ�����
	 */
	BOOL SetRegStringVal(const ATL::CString& strKeyName,const ATL::CString& strKeyValue);

	/**
	 * @brief ���ע���DWORD����ֵ
	 *
	 *
	 * @param strKeyName ����
	 * @param dwKeyValue ��ֵ
	 * @return �Ƿ��ȡ�ɹ�
	 */
	BOOL GetRegDwordVal(const ATL::CString& strKeyName,DWORD& dwKeyValue);

	/**
	 * @brief ����ע���DWORD����ֵ
	 *
	 *
	 * @param strKeyName ����
	 * @param dwKeyValue ��ֵ
	 * @return �����Ƿ�ɹ�
	 */
	BOOL SetRegDwordVal(const ATL::CString& strKeyName,DWORD dwKeyValue);

	/**
	 * @brief ���ע��������ֵ
	 *
	 *
	 * @param strKeyName ����
	 * @param ppValue	��ֵ
	 * @param pnBytes    ���س���
	 * @return �Ƿ��ȡ�ɹ�
	 */
	BOOL GetRegBinaryValue(const ATL::CString &strKeyName,BYTE **ppValue,ULONG* pnBytes);

	/**
	 * @brief ���ö�����ֵ
	 *
	 *
	 * @param strKeyName ����
	 * @param Value		 ��ֵ
	 * @param pnBytes    ���س���
	 * @return �Ƿ����óɹ�
	 */
	BOOL SetRegBinaryValue(const ATL::CString &strKeyName,const BYTE* Value,ULONG nBytes);

	/**
	 * @brief ���GUID����ע���ֵ
	 *
	 *
	 * @param strKeyName ����
	 * @param Value		 ��ֵ
	 * @return �����Ƿ��ȡ�ɹ�
	 */
	BOOL GetRegGuidValue(const ATL::CString &strKeyName,GUID &Value);

	/**
	 * @brief ����GUID����ע���ֵ
	 *
	 *
	 * @param strKeyName ����
	 * @param Value		 ��ֵ
	 * @return �����Ƿ����óɹ�
	 */
	BOOL SetRegGuidValue(const ATL::CString &strKeyName,GUID Value);

	/**
	 * @brief ɾ��ָ���ļ�ֵ
	 *
	 *
	 * @param strKeyName ����
	 * @return 
	 */
	BOOL DelKeyName(const ATL::CString& strKeyName);

	DWORD GetLastErr()
	{
		return m_dwLastErr;
	}

	/**
	 * @brief �ر�ע�����
	 *
	 *
	 */
	virtual void Close();

protected:

	/// ������
	DWORD	m_dwLastErr;

	/// �Ƿ����ע���
	BOOL	m_bOpenFlag;
};
