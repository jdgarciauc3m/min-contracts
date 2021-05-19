# Contributing to MinContracts

I encourage community feedback and contributions.
Thank you for your interest in making MinContracts better! There are several
ways you can get involved.

If you are looking for a good way to contribute to the project, please:

* have a look at the [available issue templates](https://github.com/jdgarciauc3m/min-contracts/issues/new/choose)
  and checkout the [examples of good first issues](https://github.com/jdgarciauc3m/min-contracts/contribute)
  (or [click here](https://github.com/jdgarciauc3m/min-contracts/labels/good%20first%20issue)).

* look through the [issues that need help](https://github.com/jdgarciauc3m/min-contracts/labels/help%20wanted).

* take a look at a [Pull Request template](PULL_REQUEST_TEMPLATE.md) to get yourself
  started.

## Reporting issues and suggesting new features

If you find that the project is not working properly, please file a report using
the [Bug Report template](https://github.com/jdgarciauc3m/min-contracts/issues/new?assignees=&labels=bug&template=bug_report.md&title=[BUG]).
Should the template provided not suit your needs, feel free to make a
[custom Bug Report](https://github.com/jdgarciauc3m/min-contracts/issues/new/choose),
but please label it accordingly.

Check the [Issues](https://github.com/jdgarciauc3m/min-contracts/issues)
and see if others have submitted similar feedback. You can upvote existing feedback
(using the thumbs up reaction/by commenting) or 
[submit a new suggestion](https://github.com/jdgarciauc3m/min-contracts/labels/feature).

## Acceptable Contributions

Any contributions are highly appreciate whenever they help to improve the 
MinContracts. Some general guidelines:

### DOs

* **DO** create one pull request per Issue, and ensure that the Issue is linked
  in the pull request. You can follow the [Pull Request Template](PULL_REQUEST_TEMPLATE.md)
  for this.

* **DO** follow the [Coding and Style](#style-guidelines) guidelines, and keep code
  changes as small as possible.

* **DO** include corresponding tests whenever possible.

* **DO** check for additional occurrences of the same problem in other parts of the
  codebase before submitting your PR.

* **DO** link the issue you are addressing in the pull request.

* **DO** write a good description for your pull request. More detail is better.
  Describe *why* the change is being made and *why* you have chosen a particular solution.
  Describe any manual testing you performed to validate your change.

### DO NOTs

* **DO NOT** merge multiple changes into one PR unless they have the same root cause.
* **DO NOT** merge directly into the master branch.

> Submitting a pull request for an approved Issue is not a guarantee it will be approved.
> The change must meet requirements for code quality, architecture and performance.

## Making changes to the code

### Preparing your development environment

To learn how to build the code and run tests, follow the instructions in the [README](README.md).

### Style guidelines

Please try to match the style of surrounding code as much as possible. 
In new components, prefer the patterns described in the
[C++ core guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).

### Code formatting

Use clang-format following the `.clang-format` configuration file in the 
root directory of the project.

### Testing

Your change should include tests to verify new functionality wherever possible.
Code should be structured so that it can be unit tested independently.

### Git workflow

**Each change** should either be made in a
separate branch, named as a short summary of the change.

If your change is complex, please clean up the branch history before submitting a
pull request. You can use [git rebase](https://git-scm.com/book/en/v2/Git-Branching-Rebasing)
to group your changes into a small number of commits which we can review one at a
time.

When completing a pull request, we will generally squash your changes into a single
commit. After confirming that the change works as intended, the branch *might* be
deleted, in order to prevent branch polluting. Please let us know if your pull request
needs to be merged as separate commits.

### Continuous Integration

For this project, CI is provided by [GitHub Actions](https://github.com/features/actions),
with workflows found in the [`.github/workflows` folder](.github/workflows). Workflows
are run automatically on every commit made on the main branch.

## Review process

After submitting a pull request, your code will be reviewed.

Often, multiple iterations or discussions will be needed to responding to feedback
from reviewers.

## Contributor License Agreement

Before we can review and accept a pull request from you, you'll need to sign a
Contributor License Agreement (CLA). The CLA ensures that the community is free
to use your contributions. Signing the CLA is a manual process, and you need to
do it for each pull request made. This is done by checking the boxes in the
[Pull Request Readiness Checklist of a Pull Request](PULL_REQUEST_TEMPLATE.md#Pull-Request-Readiness-Checklist).

### IMPORTANT

***Checking the aforementioned boxes means that you agree to provide your change
and/or code FREE TO USE and SUBJECT TO CHANGES for the entire community!***

You don't need to sign a CLA until you're ready to create a pull request. When your
pull request is created, it is reviewed by a team member which, if the change is
trivial (i.e. you just fixed a typo) will be labelled as `cla-not-required`.
Otherwise, it's classified as `cla-required`, if not already signed.
