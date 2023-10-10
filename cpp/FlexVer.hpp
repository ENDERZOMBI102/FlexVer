/**
 * FlexVer C++
 * A parser for the FlexVer (<https://github.com/unascribed/FlexVer>) version standard
 *
 * LICENSED UNDER CC0 1.0:
 * 	To the extent possible under law, the author has dedicated all copyright
 * 	and related and neighboring rights to this software to the public domain
 * 	worldwide. This software is distributed without any warranty.
 * 	See <https://creativecommons.org/publicdomain/zero/1.0/>
 */
#pragma once

#include <string>
#include <vector>

/**
 * Parse the given strings as freeform version strings, and compare them according to FlexVer.
 * @param a The first version string.
 * @param b The second version string.
 * @return if the two versions are equal, a negative number if `a < b`, or a positive number if `a > b`.
 */
int compare( const std::string& a, const std::string& b );

/**
 * Implements FlexVer, a SemVer-compatible intuitive comparator for free-form versioning strings as
 * seen in the wild. It's designed to sort versions like people do, rather than attempting to force
 * conformance to a rigid and limited standard. As such, it imposes no restrictions.
 *
 * Comparing two versions with differing formats will likely produce nonsensical results (garbage in, garbage out),
 * but best effort is made to correct for basic structural changes, and versions of differing length
 * will be parsed in a logical fashion.
 */
class FlexVer {
private:
	class VersionComponent;
	class NullVersionComponent;
	class SemVerPrereleaseVersionComponent;
	class NumericVersionComponent;

	std::vector<VersionComponent> components;
public:
	FlexVer() = delete;
	FlexVer( const FlexVer& other ) = delete;

	/**
	 * Compares this `FlexVer` object with another.
	 * @param other The other `FlexVer` object.
	 * @return if the two are equal, a negative number if `self < other`, or a positive number if `self > other`.
	 */
	bool compare( const FlexVer& other );

#if defined(FLEXVER_TO_STRING)
	std::string to_string() const;
#endif

	bool operator==( const FlexVer& other ) const;
	bool operator<( const FlexVer& other ) const;
	bool operator<=( const FlexVer& other ) const;
	bool operator>( const FlexVer& other ) const;
	bool operator>=( const FlexVer& other ) const;
};


class FlexVer::VersionComponent {
	virtual int compare_to( const FlexVer::VersionComponent& other ) const;
	virtual std::string to_string() const;
};

class FlexVer::NullVersionComponent : public FlexVer::VersionComponent {
	int compare_to( const FlexVer::VersionComponent& other ) const override;
	std::string to_string() const override;
};

class FlexVer::NumericVersionComponent : public FlexVer::VersionComponent {
	int compare_to( const FlexVer::VersionComponent& other ) const override;
	std::string to_string() const override;
};

class FlexVer::SemVerPrereleaseVersionComponent : public FlexVer::VersionComponent {
	int compare_to( const FlexVer::VersionComponent& other ) const override;
	std::string to_string() const override;
};



