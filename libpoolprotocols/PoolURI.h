#pragma once

#include <string>
#include <network/uri.hpp>

// A simple URI parser specifically for mining pool enpoints
namespace dev
{

enum class SecureLevel {NONE = 0, TLS12, TLS, ALLOW_SELFSIGNED};
enum class ProtocolFamily {GETWORK = 0, STRATUM};

class URI : network::uri
{
public:
	URI();
	URI(const std::string uri);

	std::string Scheme() const;
	std::string Host() const;
	std::string Port() const;
	std::string User() const;
	std::string Pswd() const;
	unsigned    ProtoVersion();
	SecureLevel ProtoSecureLevel();
	ProtocolFamily ProtoFamily();

	bool KnownScheme();

	static std::string KnownSchemes(ProtocolFamily family);


private:
	network::uri   m_uri;
};

}
