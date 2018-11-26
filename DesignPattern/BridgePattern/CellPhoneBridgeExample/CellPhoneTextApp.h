#ifndef CELL_PHONE_TEXT_APP__
#define CELL_PHONE_TEXT_APP__

#include "CellPhoneTextAppImpl.h"

class CellPhoneTextApp {
public:
	CellPhoneTextApp(CellPhoneTextAppImpl * impl) :m_pImpl(impl) {}
	virtual ~CellPhoneTextApp() {}

	virtual void Open() = 0;
	virtual void Close() = 0;

	virtual void AddText(std::string textField) {
		m_textField = textField;
	}
	virtual void SendText() {
		m_pImpl->SendTextImpl(m_recipients, m_textField);
	}
	virtual void AddRecipient(std::string recipient) {
		m_recipients.push_back(recipient);
	}
	virtual void RemoveRecipient(std::string recipient) {
		auto iter = find(m_recipients.begin(), m_recipients.end(), recipient);

		if (iter != m_recipients.end())
		{
			m_recipients.erase(iter);
		}
	}

private:
	CellPhoneTextAppImpl * m_pImpl;
	std::string m_textField;
	std::vector<std::string> m_recipients;
};
#endif // !CELL_PHONE_TEXT_APP


